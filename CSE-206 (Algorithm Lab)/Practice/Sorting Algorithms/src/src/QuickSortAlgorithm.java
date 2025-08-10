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

public class QuickSortAlgorithm {
    public static LinkedList<Integer> quickSort(LinkedList<Integer> list){
        if(list.size() <= 1) return list;
        LinkedList<Integer> left = new LinkedList<>();
        LinkedList<Integer> right = new LinkedList<>();
        int pivot = list.get(0);
        for(int i = 1; i < list.size(); i++){
            if(list.get(i) < pivot) left.add(list.get(i));
            else right.add(list.get(i));
        }
        left = quickSort(left);
        right = quickSort(right);
        left.add(pivot);
        left.addAll(right);
        return left;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // quick sort using linked list
        LinkedList<Integer> list = new LinkedList<>();

        // input
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        System.out.println("Enter the elements: ");
        for (int i = 0; i < n; i++) list.add(sc.nextInt());

        // sort
        list = quickSort(list);

        // output
        System.out.println("Sorted list: ");
        for(int i = 0; i < n; i++){
            if(i != n - 1) System.out.print(list.get(i) + " ");
            else System.out.println(list.get(i));
        }

        sc.close();
    }
}

