package com.app.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.app.pojos.Course;
import com.app.service.ICourseService;


@Controller
@RequestMapping("/course")
public class CourseController {
	
	@Autowired
	ICourseService courseService;
	
	public CourseController() {
		System.out.println("In constructor of Course controller");
	}
	
	@GetMapping("/list")
	public String getAllCourses(Model map)
	{
		List<Course>course=courseService.getAllCourses();
		map.addAttribute("courses", course);
		
		return "/course/list";
	}
	
	@GetMapping("/delete")
	public String deleteCourse(@RequestParam int id)
	{
		Course course=courseService.findCourseById(id);
		courseService.delete(course);		
	    return "redirect:/course/list";
	}
	
	

}
