package cn.tedu.springboot01;

import cn.tedu.springboot01.Mapper.BookMapper;
import cn.tedu.springboot01.entity.Book;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class BookMapperTest {
    @Autowired
    private BookMapper bm;

    @Test
    public void Test1(){
        Book b1=new Book(346,"Litte Red Book","A1","Puclisher1",500);
        Book b2=new Book(346,"Litte Yellow Book","A2","Puclisher2",600);
        Book b3=new Book(346,"Litte Blue Book","A3","Puclisher3",700);
        bm.insert(b1);
        bm.insert(b2);
        bm.insert(b3);
    }
    @Test
    public void Test2(){
        bm.updatePrice(2,1000);
        System.out.println(bm.selectById(2));
    }

    @Test void Test3(){
        bm.deleteById(3);
    }

    @Test void Test4(){
        Book book=bm.selectById(2);
        System.out.println(book);
    }

}
