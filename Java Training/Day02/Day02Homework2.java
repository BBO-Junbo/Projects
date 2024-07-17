//2.插入排序
import java.util.Arrays;
import java.util.Random;
public class Day02Homework2 {
        public static void main(String[] args) {
            int [] a=random();
            System.out.print("Array:");
            System.out.println(Arrays.toString(a));
            insertSort(a);
            System.out.print("Array after sorting:");
            System.out.println(Arrays.toString(a));
        }
        static public int [] insertSort(int [] a){
            for(int i = 1; i<a.length; ++i){
                int value = a[i];
                int j = i-1;
                //查找插入的位置
                for(; j >= 0; --j){
                    if(a[j] > value){
                        a[j+1] = a[j];
                    }else{
                        break;
                    }
                }
                a[j+1] = value;
                System.out.println("InsertSort Round "+i+Arrays.toString(a));
            }
            return a;
        }
        static int[] random(){
            int n=new Random().nextInt(10)+10;
            int []a=new int[n];
            for(int i=0;i<a.length;i++)
                a[i]=new Random().nextInt(100);
            return a;
        }
}





