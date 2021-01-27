const { response } = require("express")
const Employee = require("../models/Employee")

//show list of employees
const index = (req, res, next) => {
    Employee.find()
    .then(response => {
        res.json({response})
    })
    .catch(err => {
        res.json({message: err})
    })
}

//show single emoloyee
const show = (req, res, next) => {
    let employeeID = req.body.employeeID
    Employee.findById(employeeID)
    .then(response => {
        res.json(response)
    })
    .catch(err => {
        res.json({
            message: "Employee doesnt exist"
        })
    })
}

//add employee
const store = (req, res, next) => { 
    let employee = new Employee ( {
        id : req.body.id,
        name: req.body.name,
        email: req.body.email,
        age: req.body.age
    })
    employee.save()
    .then(response => {
        res.json({
            message : "Employee Added"
        })
    })
    .catch( err => {
        res.json({
            message: "Error occured while adding"
        })
    })
}

//update by id
const update = (req, res, next) => {
    let employeeID = req.body.employeeID

    let updatedData = {
        id : req.body.id,
        name: req.body.name,
        email: req.body.email,
        age: req.body.age 
    }

    Employee.findByIdAndUpdate(employeeID, {$set: updatedData})
    .then(response => {
        res.json({
            message: "Item updated"
        })
    })
    .catch(err => {
        message: "error while updating"
    })
}

//delete
const destroy = (req, res, next) => {
    let employeeID = req.body.employeeID
    Employee.findByIdAndRemove(employeeID)
    .then(response => {
        res.json({
            message: "Item Removed"
        })
    })
    .catch(err =>{
        res.json({
            message: "Error while removing"
        })
    })
}

module.exports = {
    index,
    show,
    store,
    update,
    destroy
}