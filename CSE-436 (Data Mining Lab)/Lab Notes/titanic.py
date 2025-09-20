import pandas as pd

# Load the test dataset
df_test = pd.read_csv('test.csv')

# Function to assign 0 for male and 1 for female
def beche_ache(row):
    if row['Sex'] == 'male':
        return 0
    else:
        return 1

# Apply the function to create a new column 'Survived'
df_test['Survived'] = df_test.apply(beche_ache, axis=1)

# Creating the final DataFrame with the desired columns
df_submission = df_test[['PassengerId', 'Survived']]

# Saving the submission DataFrame to a CSV file
df_submission.to_csv('submission.csv', index=False)

# Print the submission DataFrame
print(df_submission)

