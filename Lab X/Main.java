import java.util.*;
import java.time.*;

abstract class Element {
    abstract double norm();

    abstract void print();
}

class Point_N extends Element {
    double[] arr;
    int n;

    Point_N() {
        n = 2;
        arr = new double[n];
        arr[0] = 0.0;
        arr[1] = 0.0;
    }

    Point_N(int size) {
        // modifing this constructor to produce random values
        n = size;
        arr = new double[n];
        Random rand = new Random();
        for (int i = 0; i < n; i++) {
            // arr[i] = rand.nextDouble();
            double randomValue = (rand.nextDouble() * 99) + 1;
            arr[i] = Double.parseDouble(String.format("%.2f", randomValue));
        }
    }

    Point_N(double[] values, int size) {
        n = size;
        arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = values[i];
        }
    }

    double norm() {
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            ans += arr[i] * arr[i];
        }
        ans = Double.parseDouble(String.format("%.2f", ans));
        return ans;
    }

    void print() {
        System.out.println("Point_N class!");
        System.out.println("Printing Point_N ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("\nPrinting norm function - " + norm());
    }
}

class MultiThreadedMerge implements Runnable {
    private Element[] merge_arr;
    private int size;
    Thread t;

    public Element[] get_array() {
        return merge_arr;
    }

    MultiThreadedMerge(Element[] arr1, int size) {
        this.size = size;
        merge_arr = arr1;
        t = new Thread(this, "Merge Thread");
    }

    public static void threaded_merge() {
    }

    public void run() {
        Main.mergeSort(merge_arr);
    }
}

public class Main {
    public static void main(String[] args) {
        // question 1 - java implentation of point_n and element
        Element point_1 = new Point_N(3);
        point_1.print();
        System.out.println("Norm: " + point_1.norm());
        double[] values = { 1, 2, 3, 4, 5 };
        Element point_2 = new Point_N(values, 5);
        point_2.print();
        System.out.println("Norm: " + point_2.norm());

        // question 2
        Element[] points_test = generateRandomArray(10);
        System.out.println("\nUnsorted Array : \n");
        printArray(points_test);
        mergeSort(points_test);
        System.out.println("\nSorted Array : \n");
        printArray(points_test);
        // question 3
        Element[] points_test_multi = generateRandomArray(10);
        System.out.println("\nUnsorted Array : \n");
        printArray(points_test_multi);
       // mergeSortMultithreaded(points_test_multi, 4);
        System.out.println("\nSorted Array : \n");
        printArray(points_test_multi);

        // array of 10, 100,1000,10000
        Element[] points_10 = generateRandomArray(10);
        Element[] points_100 = generateRandomArray(100);
        Element[] points_1000 = generateRandomArray(1000);
        Element[] points_10000 = generateRandomArray(10000);
        Element[] points_100000 = generateRandomArray(100000);
        Element[] points_1000000 = generateRandomArray(1000000);

        // single-thread normal merge sort
        System.out.println("\n\nSingle-threaded merge sort:");
        measureExecutionTime("Single-threaded", points_10);
        measureExecutionTime("Single-threaded", points_100);
        measureExecutionTime("Single-threaded", points_1000);
        measureExecutionTime("Single-threaded", points_10000);
        measureExecutionTime("Single-threaded", points_100000);
        measureExecutionTime("Single-threaded", points_1000000);

        // Multithreaded merge sort with two threds is taking too much times so i made 4
        // threds
        System.out.println("\n\nMultithreaded merge sort:");
        measureExecutionTimeMultithreaded("Multithreaded", points_10, 10);
        measureExecutionTimeMultithreaded("Multithreaded", points_100, 100);
        measureExecutionTimeMultithreaded("Multithreaded", points_1000, 1000);
        measureExecutionTimeMultithreaded("Multithreaded", points_10000, 10000);
        measureExecutionTimeMultithreaded("Multithreaded", points_100000, 100000);
        measureExecutionTimeMultithreaded("Multithreaded", points_1000000, 1000000);
    }

    // single thread merge sort - normal
    static void mergeSort(Element[] arr) {
        if (arr.length > 1) {
            int mid = arr.length / 2;
            Element[] left = Arrays.copyOfRange(arr, 0, mid);
            Element[] right = Arrays.copyOfRange(arr, mid, arr.length);

            mergeSort(left);
            mergeSort(right);

            merge(arr, left, right);
        }
    }

    // merge function for both single thread and multiple thrds
    static void merge(Element[] arr, Element[] left, Element[] right) {
        int i = 0, j = 0, k = 0;

        while (i < left.length && j < right.length) {
            if (left[i].norm() < right[j].norm()) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < left.length) {
            arr[k++] = left[i++];
        }

        while (j < right.length) {
            arr[k++] = right[j++];
        }
    }

    // multi thread merge sort -2 threads
    // static void mergeSortMultithreaded(Element[] arr, int numOfThreads) {
    //     if (numOfThreads <= 1 || arr.length <= 1) {
    //         // no need for multithreading
    //         mergeSort(arr);
    //     } else {

    //         int mid = arr.length / 2;
    //         Element[] left = Arrays.copyOfRange(arr, 0, mid);
    //         Element[] right = Arrays.copyOfRange(arr, mid, arr.length);

    //         // Create two threads for sorting the halves with 4 threads each
    //         Thread leftThread = new Thread(() -> mergeSortMultithreaded(left, numOfThreads / 2));
    //         Thread rightThread = new Thread(() -> mergeSortMultithreaded(right, numOfThreads / 2));

    //         // starting the threads
    //         leftThread.start();
    //         rightThread.start();

    //         try {
    //             leftThread.join();
    //             rightThread.join();
    //         } catch (InterruptedException e) {
    //             e.printStackTrace();
    //         }

    //         merge(arr, left, right);
    //     }
    // }

    static void measureExecutionTime(String label, Element[] arr) {
        long startTime = System.nanoTime();
        mergeSort(arr);
        long endTime = System.nanoTime();

        double duration_seconds = (endTime - startTime) / 1e9;
        System.out.println(
                label + " Sorting time for array of size " + arr.length + " is " + duration_seconds * 1e3 + " ms");
    }

    static void measureExecutionTimeMultithreaded(String label, Element[] points, int size) {
        Instant start = Instant.now();
        // split this array into two halves
        Element[] subArr1 = new Element[size / 2];
        Element[] subArr2 = new Element[size - size / 2];
        System.arraycopy(points, 0, subArr1, 0, size / 2);
        System.arraycopy(points, size / 2, subArr2, 0, size - size / 2);

        // now create threads for these two halves
        MultiThreadedMerge t1 = new MultiThreadedMerge(subArr1, size / 2);
        MultiThreadedMerge t2 = new MultiThreadedMerge(subArr2, (size - size / 2));

        // threads start their merging
        t1.t.start();
        t2.t.start();
        try {
            t1.t.join();
            t2.t.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        Main.merge(points, subArr1, subArr2);
        Instant end = Instant.now();
        Duration time_taken = Duration.between(start, end);
        System.out.println(
                label + " Sorting time for array of size " + size + " is " + time_taken.toMillis() + " ms");
    }

    static Element[] generateRandomArray(int size) {
        Element[] points = new Element[size];
        for (int i = 0; i < size; i++) {
            points[i] = new Point_N(2);
        }
        return points;
    }

    static void printArray(Element[] arr) {
        for (Element element : arr) {
            element.print();
        }
    }
}