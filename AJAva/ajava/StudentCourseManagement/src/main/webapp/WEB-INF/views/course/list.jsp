<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 <%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
 <%@taglib uri="http://www.springframework.org/tags" prefix="spring"%>
 
<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" href="/css/style.css" type="text/css">
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<h1>Course List</h1>

<h1>All Available Course</h1>
	<table>
		<tr>
			<th>Course Name</th>
			
			<th></th>
			<th></th>
		</tr>

		<c:forEach var="c" items="${requestScope.courses}">
			<tr>
				
				<td>${c.courseName}</td>
				<td><a href="<spring:url value='/course/delete?id=${c.id}'/>">Delete </a></td>
				<td><a href="<spring:url value='/student/add?id=${c.id}'/>">Admit Student </a></td>
			</tr>
		</c:forEach>
	</table>



</body>
</html>