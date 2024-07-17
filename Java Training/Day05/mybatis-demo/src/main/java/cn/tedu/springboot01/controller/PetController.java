package cn.tedu.springboot01.controller;

import cn.tedu.springboot01.entity.Pet;
import cn.tedu.springboot01.mapper.PetMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.Date;
import java.util.List;

@RestController
public class PetController {
    @Autowired
    private PetMapper m;
    @PostMapping("/addPet")
    public String add(@RequestBody Pet pet){
        pet.setCreateTime(new Date());
        pet.setUpdateTime(new Date());
        m.insert(pet);

        return "{\"result\":\"ok\"}";
    }
    @GetMapping("/petList")
    public List<Pet> list(){
        return m.findAll();
    }

    @PostMapping("/delPet")
    public  String delPer(int petId){
        m.deleteById(petId);
        return "{\"result\":\"ok\"}";
    }
    @PostMapping("/updateName")
    public String undateName(int petId, String petName){
        m.updateName(petId,petName);
        return "{\"result\":\"ok\"}";

    }


}


