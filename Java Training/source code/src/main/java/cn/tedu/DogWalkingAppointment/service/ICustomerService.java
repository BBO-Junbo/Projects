package cn.tedu.DogWalkingAppointment.service;

import cn.tedu.DogWalkingAppointment.entity.Customer;
import cn.tedu.DogWalkingAppointment.entity.User;

public interface ICustomerService {
    void regc(Customer customer);

    Customer getByCustomerId(Integer cid);
}
