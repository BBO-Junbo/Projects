//3.任意两个有序数组，合并成一个有序数组
//  例如
//  a=[1,1,2,5,6,9,12,66]
//  b=[2,6,7,7,10]
//  合并后=[1,1,2,2,5,6,6,7,7,9,10,12,66]
import java.util.Arrays;
public class Day02HomeWork3 {
    public static void main(String[] args) {
        int []a={1,1,2,5,6,9,12,66};
        int []b={2,6,7,7,10};
        int []c=new int[a.length+b.length];
        int pa=0,pb=0;
        for(int i=0;i<c.length;i++){
            if(pa<a.length&&pb<b.length){
                 if(a[pa]<=b[pb]){
                    c[i]=a[pa];
                    pa++;
                }else if(b[pb]<a[pa]||pa==-1){
                    c[i]=b[pb];
                    pb++;
                }
            }else if(pa<a.length&&pb==b.length){
                c[i]=a[pa];
                pa++;
            }else if(pa==a.length&&pb<b.length){
                c[i]=b[pb];
                pb++;
            }
        }
        System.out.println(Arrays.toString(c));
    }

}
