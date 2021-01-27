<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://ajax.googleapis.com/ajax/libs/angularjs/1.6.9/angular.min.js"></script>
    <title>Document</title>
</head>
<body>
    <div ng-app="myApp" ng-controller="myCtrl">

        First Name: <input type="text" ng-model="firstName"><br>
        Last Name: <input type="text" ng-model="lastName"><br>
        email: <input type="text" ng-model="email"><br>

        <label for="cars">Choose a car:</label>
        <select name="cars" id="cars" ng-model="car">
        <option value="volvo">Volvo</option>
        <option value="Saab">Saab</option>
        <option value="Mercedes">Mercedes</option>
        <option value="Audi">Audi</option>
        </select>
        <br>

        <h1>Name: {{firstName + " " + lastName}}</h1>
        <small>email : {{email}}</small>
        <p>Car chosen: {{car}}</p>

        <div>
            num1: <input type="number" ng-model="num1" ng-change="product()" /> 
            <br><br> 
            num2: <input type="number" ng-model="num2" ng-change="product()" /> 
            <br><br> 
            <b>Product:</b> <span ng-bind="result"></span> 
        </div>
        
    </div>

        <script>
            var app = angular.module('myApp', []);
            app.controller('myCtrl', function($scope) {
                $scope.firstName = "John";
                $scope.lastName = "Doe";
                $scope.email = "";
                $scope.car = "";
                $scope.num1 = 1; 
                $scope.num2 = 1; 
                $scope.product = function () { 
                    $scope.result = ($scope.num1 * $scope.num2); 
                } 
            });
        </script>
</body>
</html>


<!-- The ng-controller Directive in AngularJS is used to add controller to the application. It can be used to add methods, functions and variables that can be called on so me event like click, etc to perform certain action. -->

<!-- The ng-bind Directive in AngularJS is used to bind/replace the text content of any particular HTML element with the value that is entered in the given expression. The value of specified HTML content updates whenever the value of the expression changes in ng-bind directive. -->

<!-- ngModel is a directive which binds input, select and textarea, and stores the required user value in a variable and we can use that variable whenever we require that value. -->
