package cn.tedu.springboot01.mapper;
import cn.tedu.springboot01.entity.Pet;

import java.util.List;

public interface PetMapper {

    int insert(Pet pet);
    int updateName(int id,String name);

    Pet findById(int id);
    List<Pet> findAll();

    int deleteById(int id);
}
