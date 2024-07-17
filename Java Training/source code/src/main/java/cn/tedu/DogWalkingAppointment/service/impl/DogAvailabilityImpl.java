package cn.tedu.DogWalkingAppointment.service.impl;

import cn.tedu.DogWalkingAppointment.entity.Dog;
import cn.tedu.DogWalkingAppointment.entity.DogAvailability;
import cn.tedu.DogWalkingAppointment.entity.DogReview;
import cn.tedu.DogWalkingAppointment.ex.AccessDeniedException;
import cn.tedu.DogWalkingAppointment.ex.AvalibilityNotFoundException;
import cn.tedu.DogWalkingAppointment.ex.DeleteException;
import cn.tedu.DogWalkingAppointment.ex.UpdateException;
import cn.tedu.DogWalkingAppointment.mapper.DogAvailabilityMapper;
import cn.tedu.DogWalkingAppointment.service.IDogAvailabilityService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Date;
import java.util.List;

@Service
public class DogAvailabilityImpl implements IDogAvailabilityService {
    @Autowired
    private DogAvailabilityMapper dogAvailabilityMapper;
    @Override
    public void addNewAvailability(Integer dogId,String username,DogAvailability dogAvailability){
        dogAvailability.setDogId(dogId);
        dogAvailability.setCreatedUser(username);
        dogAvailability.setCreatedTime(new Date());
        dogAvailability.setModifiedUser(username);
        dogAvailability.setModifiedTime(new Date());
        dogAvailabilityMapper.insert(dogAvailability);
    }
    @Override
    public void deleteAvalibilityId(Integer availabilityId){
        DogAvailability result=dogAvailabilityMapper.findByAvailabilityId(availabilityId);
        // 判断查询结果是否为null
        if (result == null) {
            // 是：抛出AddressNotFoundException
            throw new AvalibilityNotFoundException("该预约不存在");
        }
        if (!result.getAvailabilityId().equals(availabilityId)) {
            // 是：抛出AccessDeniedException：非法访问
            throw new AccessDeniedException("非常访问");
        }
        Integer rows1 = dogAvailabilityMapper.deleteByAvailabilityId(availabilityId);
        if (rows1 != 1) {
            throw new DeleteException("删除可遛时间时出现未知错误，请联系系统管理员");
        }
    }
    @Override
    public List<DogAvailability> getByDog_id(Integer dogId){
        List<DogAvailability> list = dogAvailabilityMapper.findByDogid(dogId);
        for (DogAvailability dogAvailability: list) {
            dogAvailability.setCreatedUser(null);
            dogAvailability.setCreatedTime(null);
            dogAvailability.setModifiedUser(null);
            dogAvailability.setModifiedTime(null);
        }
        return list;
    }

    @Override
    public List<DogAvailability> getAllAvailability(){
        List<DogAvailability> list = dogAvailabilityMapper.findAllDogAvailability();
        for (DogAvailability dogAvailability: list) {
            dogAvailability.setCreatedUser(null);
            dogAvailability.setCreatedTime(null);
            dogAvailability.setModifiedUser(null);
            dogAvailability.setModifiedTime(null);
        }
        return list;
    }
    @Override
    public void changeIsReserved(Integer aid){
        Integer n=dogAvailabilityMapper.changeIsReservedByAvailabilityId(aid);
        if (n != 1) {
            // 是：抛出UpdateException异常
            throw new UpdateException("更新数据时出现未知错误，请联系系统管理员");
        }
    }


}
