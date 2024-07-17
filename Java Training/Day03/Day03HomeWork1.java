//1. 使用LinkedList队列操作解决求第n个丑数问题
//把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但7、14不是，
//因为它们包含质因子7。 习惯上我们把1当做是第一个丑数。
//前20个丑数为：1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27, 30, 32, 36。

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.concurrent.LinkedBlockingDeque;

public class Day03HomeWork1 {
    public static void main(String[] args) {
        System.out.println("Which ugly number do you wanna get? Please enter an integer:");
        int n=new Scanner(System.in).nextInt();
        ArrayList<Integer> uglynum = new ArrayList<>();
        LinkedList x2=new LinkedList<>();
        LinkedList x3=new LinkedList<>();
        LinkedList x5=new LinkedList<>();
        uglynum.add(1);
        for(int i=0;i<=n;i++){
            x2.offer(uglynum.get(i)*2);
            x3.offer(uglynum.get(i)*3);
            x5.offer(uglynum.get(i)*5);
            Integer next=Math.min((int)x2.peek(),(int)Math.min((int)x3.peek(),(int)x5.peek()));
            uglynum.add(next);
            if(x2.peek()==next) x2.poll();
            if(x3.peek()==next) x3.poll();
            if(x5.peek()==next) x5.poll();
        }
        System.out.println("NO."+n+" ugly number is: "+uglynum.get(n-1));

    }
}
