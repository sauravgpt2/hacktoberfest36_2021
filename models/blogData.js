const mongoose = require("mongoose");

const blogSchema = new mongoose.Schema({

    title:String,
    image: String,
    author: String,
    content: String,
    comments: [
        {
            type:mongoose.Schema.Types.ObjectId,
            ref:'Comments'
        }
    ]

  });

  module.exports = mongoose.model('Blog',blogSchema) 