package cn.tedu.DogWalkingAppointment.service.impl;

import cn.tedu.DogWalkingAppointment.entity.Dog;
import cn.tedu.DogWalkingAppointment.ex.AccessDeniedException;
import cn.tedu.DogWalkingAppointment.ex.DeleteException;
import cn.tedu.DogWalkingAppointment.ex.DogNotFoundException;
import cn.tedu.DogWalkingAppointment.ex.UpdateException;
import cn.tedu.DogWalkingAppointment.mapper.DogMapper;
import cn.tedu.DogWalkingAppointment.service.IDogService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.Date;
import java.util.List;

@Service
public class DogServiceImpl implements IDogService {
    @Autowired
    private DogMapper m;
    @Override
    public void addNewDog(Integer userId, String username, Dog dog) {

        // 补全数据：将参数uid封装到参数address中
        dog.setUserId(userId);
        dog.setMasterName(username);
        // 补全数据：4项日志
        Date now = new Date();
        dog.setCreatedUser(username);
        dog.setCreatedTime(now);
        dog.setModifiedUser(username);
        dog.setModifiedTime(now);
        Integer rows = m.insert(dog);

    }

    @Override
    public List<Dog> getByUid(Integer userId) {
        List<Dog> list = m.findByUid(userId);
        for (Dog dog : list) {
            dog.setUserId(null);
            dog.setCreatedUser(null);
            dog.setCreatedTime(null);
            dog.setModifiedUser(null);
            dog.setModifiedTime(null);
        }
        return list;
    }
    @Override
    public Dog getByDogId(Integer dogId){

        Dog result=m.findByDogId(dogId);
        return result;
    }
    @Override
    public Dog findByDogId(Integer dogId) {
        Dog dog = m.findByDogId(dogId);

        if (dog != null) {
            dog.setUserId(null);
            dog.setCreatedUser(null);
            dog.setCreatedTime(null);
            dog.setModifiedUser(null);
            dog.setModifiedTime(null);
        }

        return dog;
    }
    @Override
    public void updateDogById(Dog dog) {
        Dog result = m.findByDogId(dog.getDogId());
        // 判断查询结果是否为null
        if (result.getDogId()== null) {
            throw new DogNotFoundException("尝试访问的狗狗数据不存在");
        }

        // 判断查询结果中的dogId与参数dogId是否不一致(使用equals()判断)
        if (result.getDogId()!=dog.getDogId()) {
            // 是：抛出AccessDeniedException：非法访问
            throw new AccessDeniedException("非法访问");
        }

        // 调用m的更新狗狗信息方法，传入参数dog
        Integer rows = m.updateDogById(dog);

        if (rows != 1) {
            throw new UpdateException("更新狗狗数据时出现未知错误，请联系系统管理员");
        }
    }
    @Override
    public List<Dog> getAllDog() {
        List<Dog> list = m.findAllDog();
        for (Dog dog : list) {
            dog.setUserId(null);
            dog.setCreatedUser(null);
            dog.setCreatedTime(null);
            dog.setModifiedUser(null);
            dog.setModifiedTime(null);
        }
        return list;
    }
    @Transactional
    @Override
    public void delete(Integer dogId, Integer userId, String username) {
        // 根据参数dogId，调用findByAid()查询收货地址数据
        Dog result = m.findByDogId(dogId);
        // 判断查询结果是否为null
        if (result == null) {
            throw new DogNotFoundException("尝试访问的狗狗数据不存在");
        }

        // 判断查询结果中的uid与参数uid是否不一致(使用equals()判断)
        if (!result.getUserId().equals(userId)) {
            // 是：抛出AccessDeniedException：非法访问
            throw new AccessDeniedException("非常访问");
        }

        // 根据参数aid，调用deleteByAid()执行删除
        Integer rows1 = m.deleteByDogId(dogId);
        if (rows1 != 1) {
            throw new DeleteException("删除狗狗数据时出现未知错误，请联系系统管理员");
        }


    }
}
