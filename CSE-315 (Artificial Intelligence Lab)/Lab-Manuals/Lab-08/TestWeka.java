import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Random;

public class TestWeka {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        simpleWekaTrain("C:\\Program Files\\Weka-3-8\\data\\weather.numeric.arff");

        // TODO code application logic here
    }
    public static void simpleWekaTrain(String filepath) throws
    FileNotFoundException, Exception {
        try {
            //Reading training arff or csv file
            FileReader trainreader = new FileReader(filepath);
            Instances train = new Instances(trainreader);
            train.setClassIndex(train.numAttributes() - 1);
            //Instance of NN

            //Setting Parameters
            //MultilayerPerceptron mlp = new MultilayerPerceptron();
            //mlp.setLearningRate(0.3);
            //mlp.setMomentum(0.2);
            //mlp.setTrainingTime(500);
            //mlp.setHiddenLayers("4");
            //mlp.buildClassifier(train);
            J48 j48 = new J48();
            j48.setConfidenceFactor(0.25 f);
            j48.buildClassifier(train);
            Evaluation eval = new Evaluation(train);
            eval.crossValidateModel(j48, train, 10, new Random(1));
            //eval.crossValidateModel(mlp, train, 10, new Random(1));
            //System.out.println(eval.errorRate()); //Printing Training Mean root squared Error
            System.out.println(eval.toSummaryString()); //Summary of Training

            // Print Confusion Matrix
            System.out.println("=== Confusion Matrix ==="); //Summary of Training
            double conMat[][] = eval.confusionMatrix();
            int i, j;
            for (i = 0; i < conMat.length; ++i) {
                for (j = 0; j < conMat[i].length; ++j) {
                    System.out.print(conMat[i][j] + " ");
                }
                System.out.println("");
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        // this lines of code can be used for saving training model and use the saved model for testing when required
        //weka.core.SerializationHelper.write("trained.model", mlp); // save tained model

        // use saved trained model for testing on data "Instance"
        //J48 classifier = (J48) weka.core.SerializationHelper.read(new
        FileInputStream(new File("ModelPath"));
        //eval.evaluateModel(classifier, data,plainText);
    }
}