import java.util.Arrays;
import java.util.Random;

public class Day02HomeWork1 {
    public static void main(String[] args) {
        int [] a=random();
        System.out.print("Array:");
        System.out.println(Arrays.toString(a));
        System.out.print("Array after sorting:");
        selectSort(a);
        System.out.println(Arrays.toString(a));
    }
    static public int [] selectSort(int [] n){

        for(int i=0;i<n.length;i++){
            int minloc=i;
            for(int j=i;j< n.length;j++){
                if(n[j]<n[minloc])
                    minloc=j;
            }
            int temp=n[i];
            n[i]=n[minloc];
            n[minloc]=temp;
        }
        return n;
    }
    static int[] random(){
        int n=new Random().nextInt(10)+10;
        int []a=new int[n];
        for(int i=0;i<a.length;i++)
            a[i]=new Random().nextInt(100);
        return a;
    }
}
//第二天作业：
//作业
//1.选择排序
//
//2.插入排序
//
//3.任意两个有序数组，合并成一个有序数组
//  例如
//  a=[1,1,2,5,6,9,12,66]
//  b=[2,6,7,7,10]
//  合并后=[1,1,2,2,5,6,6,7,7,9,10,12,66]