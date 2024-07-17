package cn.tedu.DogWalkingAppointment.controller;

import cn.tedu.DogWalkingAppointment.entity.Dog;
import cn.tedu.DogWalkingAppointment.service.IDogService;
import cn.tedu.DogWalkingAppointment.util.JsonResult;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.File;
import java.util.List;
import java.util.Random;
import java.util.UUID;

@RestController
@RequestMapping("/dogs")
public class DogController extends BaseController{
    @Autowired
    private IDogService service;
    @RequestMapping("add_new_dog")
    public void addNewDog(Dog dog, MultipartFile imageUrl2, HttpSession session, HttpServletResponse response) throws  Exception{
        // 从Session中获取
        Integer userId = getUidFromSession(session);
        String username = getUsernameFromSession(session);

        //保存图片
        if (null!=imageUrl2){
            //获取文件同学情
            String fileSub = imageUrl2.getOriginalFilename().substring(imageUrl2.getOriginalFilename().lastIndexOf(".")).toLowerCase();
            //如果是图片
            if (".jpg".equals(fileSub) || ".jpeg".equals(fileSub) || ".png".equals(fileSub) || ".gif".equals(fileSub)) {
                //随机生成新文件名
                Random d  = new Random();
                String imgName = UUID.randomUUID().toString().replace("-", "") + d.nextInt(10000) + "" + fileSub;
                //获取的文件保存到D:/dogimg/ + imgName
                imageUrl2.transferTo(new File("D:/dogimg/", imgName));
                //保存图片路径为资源隐射后的路径
                dog.setImageUrl("/dogimg/"+imgName);
            }
        }
        // 调用业务对象的方法执行业务
        service.addNewDog(userId,username,dog);
        // 响应成功 重定向到我的狗狗 可以改其他的html
        response.sendRedirect("http://localhost:8080/web/masterweb/mydogs.html");
//        return new JsonResult<Void>(200,null,null);
    }
    @GetMapping({"", "/"})
    public JsonResult<List<Dog>> getByUid(HttpSession session) {
        Integer userId = getUidFromSession(session);
        List<Dog> data = service.getByUid(userId);
        return new JsonResult<>(200,null,data);
    }
    @GetMapping("getByDogId")
    public JsonResult<Dog> getByDogid(Integer dogId) {
        Dog data = service.getByDogId(dogId);
        return new JsonResult<>(200,null,data);
    }
    @RequestMapping("/get_all_dog")
    public JsonResult<List<Dog>> getAllDog() {
        List<Dog> data = service.getAllDog();
        return new JsonResult<>(200,null,data);
    }
    @RequestMapping("{dogId}/delete")
    public JsonResult<Void> delete(@PathVariable("dogId") Integer dogId, HttpSession session) {
        Integer userId = getUidFromSession(session);
        String username = getUsernameFromSession(session);
        service.delete(dogId, userId, username);
        return new JsonResult<Void>(200,null,null);
    }
    @RequestMapping("/{dogId}/update")
    public JsonResult<Void> updateDog(@PathVariable("dogId") Integer dogId, @RequestBody Dog updatedDog, HttpSession session) {
        updatedDog.setDogId(dogId);
        service.updateDogById(updatedDog);

        return new JsonResult<>(200, null, null);
    }
}
