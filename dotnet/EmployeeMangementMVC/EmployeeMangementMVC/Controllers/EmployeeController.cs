using EmployeeMangementMVC.Database_Context;
using EmployeeMangementMVC.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace EmployeeMangementMVC.Controllers
{
    public class EmployeeController : Controller
    {
      
		EmployeeContext context = new EmployeeContext();
        
        public ActionResult Index()
        {
             var Emplist = context.Employee.ToList();
             return View(Emplist);
        }

        [HttpGet]
        public ActionResult Create()
        {

            return View();
        }

        [HttpPost]
        public ActionResult Create(Employee emp)
        {
            if (ModelState.IsValid)
            {
                context.Employee.Add(emp);
                context.SaveChanges();
                return RedirectToAction("Index", "Employee");
            }
            return View();

        }

        [HttpGet]
        public ActionResult Edit(int id)
        {
            var EmpList = context.Employee.ToList();
            var Employee = EmpList.FirstOrDefault(e=> e.EmpId == id);

            return View(Employee);
        }

        [HttpPost]
        public ActionResult Edit(Employee emp)
        {
            if (ModelState.IsValid)
            {
                context.Entry(emp).State = EntityState.Modified;
                context.SaveChanges();
                return RedirectToAction("Index", "Employee");
            }
            else
            {
                return View();
            }

        }
    
        [HttpGet]
        public ActionResult Delete(int id)
        {
            var emp = context.Employee.Find(id);
            return View(emp);
        }

        [HttpPost]
        public ActionResult Delete(int id,Employee Emp)
        {
            var EmpList = context.Employee.ToList();
            Emp = EmpList.FirstOrDefault(e => e.EmpId == id);
            context.Employee.Remove(Emp);
            context.SaveChanges();
            return RedirectToAction("Index", "Employee");
        }


    }
}