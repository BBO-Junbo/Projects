package cn.tedu.springboot01.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Book {


    int id ;
    String title;
    String author;
    String publisher;
    int price  ;

}
