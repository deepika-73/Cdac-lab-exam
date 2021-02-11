using EmployeeMangementMVC.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace EmployeeMangementMVC.Database_Context
{
    public class EmployeeContext:DbContext
    {
        public EmployeeContext() : base("EmployeeDb")
        {

        }
        public DbSet<Employee> Employee { get; set; }

    }
}