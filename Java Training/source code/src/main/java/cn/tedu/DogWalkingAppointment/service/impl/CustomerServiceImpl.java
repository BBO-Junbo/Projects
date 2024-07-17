package cn.tedu.DogWalkingAppointment.service.impl;

import cn.tedu.DogWalkingAppointment.entity.Customer;
import cn.tedu.DogWalkingAppointment.mapper.CustomerMapper;
import cn.tedu.DogWalkingAppointment.service.ICustomerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Date;
import java.util.UUID;

@Service
public class CustomerServiceImpl implements ICustomerService {
    @Autowired
    CustomerMapper customerMapper;
    @Override
    public void regc(Customer customer){
        Customer c=customerMapper.findByname(customer.getCustomerName());



        // 判断查询结果是否不为null
        // 是：表示用户名已被占用，则抛出UsernameDuplicateException异常
        if(c!=null){
            return;
        }
        Date date=new Date();
        customer.setModifiedTime(date);
        customer.setCreatedTime(date);
        customer.setCreatedUser(customer.getCustomerName());
        customer.setModifiedUser(customer.getCustomerName());

        String salt= UUID.randomUUID().toString();

        // 表示用户名没有被占用，则允许注册
        // 调用持久层Integer insert(User user)方法，执行注册并获取返回值(受影响的行数)
        // 判断受影响的行数是否不为1
        // 是：插入数据时出现某种错误，则抛出InsertException异常
        Integer n=customerMapper.insert(customer);//返回插入行数
        if(n==null||n!=1){
            return;
        }
    }
    @Override
    public Customer getByCustomerId(Integer cid){
        return customerMapper.findByCustomerId(cid);
    }
}
