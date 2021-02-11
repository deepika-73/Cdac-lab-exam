using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace EmployeeMangementMVC.Models
{
    [Table("Employee")]
    public class Employee
    {
        [Key]
        public int EmpId { get; set; }
        [Required(ErrorMessage = "First Name Required,Please provide Name.")]
        public string EmpName { get; set; }
        [Required(ErrorMessage = "City is Required.")]
        public string City { get; set; }
        [Required(ErrorMessage = "Address is Required.")]
        [DataType(DataType.MultilineText)]
        public string Address { get; set; }
    }
}