package cn.tedu.springboot01;

import cn.tedu.springboot01.entity.Pet;
import cn.tedu.springboot01.mapper.PetMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Date;
import java.util.List;

@SpringBootTest
public class PetMapperTest {
    @Autowired
    private PetMapper m;

    @Test
   public void test1(){
        Pet p = new Pet(0, "Amy", "M", new Date(), new Date(), new Date());
        m.insert(p);

    }
    @Test
    public void test2(){
        m.updateName(1,"Tim");
    }
    @Test
    public void test3(){
        Pet p1=m.findById(1);
        System.out.println(p1);
    }
    @Test
    public void test4(){
        List<Pet> l=m.findAll();
        System.out.println(l);
    }

}
