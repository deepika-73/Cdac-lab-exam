package com.app.service;

import java.util.List;

import javax.transaction.Transactional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.app.pojos.Course;
import com.app.repository.CourseRepository;

@Service
@Transactional
public class CourseServiceImpl implements ICourseService {

	@Autowired
	private CourseRepository repo;
	
	@Override
	public List<Course> getAllCourses() {
		return repo.findAll();
	}

	@Override
	public Course findCourseById(int id) {
		return repo.findById(id).get();
	}

	@Override
	public void delete(Course course) {
		repo.delete(course);		
	}
	
	

}
