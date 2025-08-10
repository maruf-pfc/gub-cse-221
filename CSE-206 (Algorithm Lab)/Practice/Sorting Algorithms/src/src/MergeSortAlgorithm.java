/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package src;

/**
 *
 * @author maruf
 */

import java.util.LinkedList;
import java.util.Scanner;

class MergeSortAlgorithm {
    public static LinkedList<Integer> mergeSort(LinkedList<Integer> list){
        if(list.size() == 1) return list;
        LinkedList<Integer> left = new LinkedList<>();
        LinkedList<Integer> right = new LinkedList<>();
        for(int i = 0; i < list.size(); i++){
            if(i < list.size() / 2) left.add(list.get(i));
            else right.add(list.get(i));
        }
        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }
    public static LinkedList<Integer> merge(LinkedList<Integer> left, LinkedList<Integer> right){
        LinkedList<Integer> result = new LinkedList<>();
        int i = 0, j = 0;
        while(i < left.size() && j < right.size()){
            if(left.get(i) < right.get(j)){
                result.add(left.get(i));
                i++;
            }
            else{
                result.add(right.get(j));
                j++;
            }
        }
        while(i < left.size()){
            result.add(left.get(i));
            i++;
        }
        while(j < right.size()){
            result.add(right.get(j));
            j++;
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // merge sort using linked list
        LinkedList<Integer> list = new LinkedList<>();

        // input
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        System.out.println("Enter the elements: ");
        for (int i = 0; i < n; i++) list.add(sc.nextInt());

        // sort
        list = mergeSort(list);

        // output
        System.out.println("Sorted list: ");
        for(int i = 0; i < n; i++){
            if(i != n - 1) System.out.print(list.get(i) + " ");
            else System.out.println(list.get(i));
        }
    }
}

/*
Enter the number of elements: 5
Enter the elements: 
3 2 1 5 4
Sorted list: 
1 2 3 4 5
*/
