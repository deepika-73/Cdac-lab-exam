using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace EmployeeMangementMVC.Controllers
{
    public class ErrorController : Controller
    {
        // GET: Error
        [HandleError]
        public ActionResult Error()
        {
            return View();
        }
        [HandleError]
        public ActionResult NotFound()
        {
            return View();
        }
    }
}