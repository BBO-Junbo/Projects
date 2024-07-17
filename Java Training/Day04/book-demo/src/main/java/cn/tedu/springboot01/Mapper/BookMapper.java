package cn.tedu.springboot01.Mapper;

import cn.tedu.springboot01.entity.Book;

public interface BookMapper {
    void insert(Book book);
    void updatePrice(int id,int price);
    void deleteById(int id);
    Book selectById(int id);

}
