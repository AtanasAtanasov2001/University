package com.geometry.utils;

public class SelectionSort {
    public static void sortArray(Comparable[] arr) {
        if(arr == null || arr.length == 0) return;

        int smallest;
        for (int i = 0; i < arr.length - 1; i++) {
            smallest = i;

            for (int j = i + 1; j < arr.length; j++) {
                if(arr[j].compareTo(arr[smallest]) < 0)
                    smallest = j;
            }
            if(smallest != i) {
                Comparable temp = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = temp;
            }
        }
    }
}
