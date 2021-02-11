<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib uri="http://www.springframework.org/tags/form" prefix="form" %>

<!DOCTYPE html>
<html>
<head>
<style type="text/css">

h1{
	 text-align: center; 
	background-color: #E6E6FA;
}
</style>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<h1>Admission New Student</h1>
<div>
		<form:form method="post" modelAttribute="student">
		<table style="background-color: #E6E6FA; margin: auto; margin-top: 5%; padding: 30px;">
			<tr>
				<td>Enter Name</td>
				<td><form:input path="name" /></td>
			</tr>
			<tr>
				<td>Enter Address</td>
				<td><form:input path="address" /></td>
			</tr>
			<tr>
				<td>Enter DOB</td>
				<td><form:input type="date" path="DateOfBirth" /></td>
			</tr>
			<tr>
				<td>Enter CGPA</td>
				<td><form:input type="number" path="cgpa" /></td>
			</tr>
			
				<tr>
				<td><input type="submit" value="Admit Student" /></td>
			</tr>
		</table>
	</form:form>

</div>

</body>
</html>