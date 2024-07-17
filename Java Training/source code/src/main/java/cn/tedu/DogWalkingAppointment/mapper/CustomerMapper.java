package cn.tedu.DogWalkingAppointment.mapper;

import cn.tedu.DogWalkingAppointment.entity.Customer;
import cn.tedu.DogWalkingAppointment.entity.User;

public interface CustomerMapper{
    Integer insert(Customer customer);
    Customer findByname(String name);
    Customer findByUserId(Integer uid);

    Customer findByCustomerId(Integer cid);
}
