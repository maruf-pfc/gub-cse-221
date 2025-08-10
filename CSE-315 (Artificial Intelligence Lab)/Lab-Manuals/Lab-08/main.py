import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import cross_val_predict, cross_val_score, StratifiedKFold
from sklearn.metrics import confusion_matrix, classification_report
from sklearn.preprocessing import LabelEncoder

def simple_weka_train(filepath):
    # Load the ARFF file using scipy
    from scipy.io import arff
    data, meta = arff.loadarff(filepath)
    df = pd.DataFrame(data)

    # Convert byte strings to normal strings if needed
    for column in df.select_dtypes([object]).columns:
        df[column] = df[column].apply(lambda x: x.decode('utf-8'))

    # Encode categorical attributes if necessary
    le_dict = {}
    for column in df.columns:
        if df[column].dtype == 'object':
            le = LabelEncoder()
            df[column] = le.fit_transform(df[column])
            le_dict[column] = le

    # Define features and labels
    X = df.iloc[:, :-1]
    y = df.iloc[:, -1]

    # Create the model (equivalent to J48)
    clf = DecisionTreeClassifier(criterion='entropy', random_state=1)

    # Evaluate with 10-fold cross-validation
    cv = StratifiedKFold(n_splits=10, shuffle=True, random_state=1)
    y_pred = cross_val_predict(clf, X, y, cv=cv)
    scores = cross_val_score(clf, X, y, cv=cv)

    print("=== Summary ===")
    print(f"Accuracy: {scores.mean():.4f} (+/- {scores.std():.4f})\n")

    print("=== Classification Report ===")
    print(classification_report(y, y_pred))

    print("=== Confusion Matrix ===")
    print(confusion_matrix(y, y_pred))

if __name__ == "__main__":
    # Update the path below to your ARFF file location
    filepath = "./weather.numeric.arff"
    simple_weka_train(filepath)
