import java.util.Scanner;

class MatrixRepresentation{
    static int[][] matrix = new int[20][20];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        System.out.println("Enter the edges of the matrix: ");
        
        while(m-- > 0){
            char j, k;
            j = sc.next().charAt(0);
            k = sc.next().charAt(0);
            matrix[j-97][k-97] = 1;
            matrix[k-97][j-97] = 1;
        }

        System.out.println("Matrix Representation: ");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}

/*
5 6
Enter the edges of the matrix: 
a b
a c
a e
b d
c d
c e
Matrix Representation: 
0 1 1 0 1 
1 0 0 1 0 
1 0 0 1 1 
0 1 1 0 0 
1 0 1 0 0
*/