const mongoose = require("mongoose")
const Schema = mongoose.Schema

const employeeSchema = new Schema({
    id: {
        type: String
    },
    name: {
        type:String
    },
    email: {
        type: String
    },
    age: {
        type: Number
    },
}, {timestamps: true})

const Employee = mongoose.model("Employee", employeeSchema)
module.exports = Employee