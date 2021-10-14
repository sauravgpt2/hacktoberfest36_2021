const mongoose = require("mongoose")

const commentSchema = new mongoose.Schema ({
    title:String,
    comment:String,
    date:{
        type: Date,
        default: Date.now
      },
     
}) 

const Comments = mongoose.model('Comments',commentSchema)

module.exports = Comments;