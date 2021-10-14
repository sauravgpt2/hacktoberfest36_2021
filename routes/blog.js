const express = require("express");
let blogRouter  = express.Router();
const Blog = require('../models/blogData')
const Comments = require("../models/commentData")
const methodOverride = require("method-override"); 



blogRouter.use(methodOverride("_method"));
blogRouter.use(express.urlencoded({ extended: true }));



blogRouter.route('/')
.get(async(req, res) => {

    const blog = await(Blog.find({}))
    res.render("blog/index",{blog})

  });
  
  blogRouter.route('/new')
  .get( (req, res) => {
    res.render("blog/new");
  })

  .post(async(req,res)=>{
    const blog = req.body;
    try{
    await Blog.create(blog);
    }
    catch(err){
      console.log( err);
    }
    res.redirect("/blog")
  });
  
  
  blogRouter.route("/:id")
    .get(async (req, res) => {
    
        const blog = await Blog.findById(req.params.id).populate('comments');
        res.render('blog/show',{blog})
  })
    .delete(async (req,res)=>{
        await Blog.findByIdAndDelete(req.params.id);
        res.redirect('/blog')
    })

    .patch(async(req,res)=>{
        const { id } = req.params;
    const upDatedBlog = req.body;
    Blog.findByIdAndUpdate(
      id,
      {
        title: upDatedBlog.title,
        image: upDatedBlog.image,
        author: upDatedBlog.author,
        content: upDatedBlog.content,
      },
      function (err, docs) {
        if (err) {
          console.log(err);
        } else {
          res.redirect("/blog");
        }
      })
      
    
    })
    .put(async (req,res)=>{
 
        const blog =  await Blog.findById(req.params.id);
        const comment = new Comments(
            {
                title: req.body.title,
                comment:req.body.comment
            }
        )
        console.log(comment)
        blog.comments.push(comment);
        
        await blog.save();
        await comment.save();
        res.redirect("/blog"+"/"+ req.params.id) });
  
  
  
  blogRouter.route("/:id/edit")
  .get( async (req, res) => {
    const blog = await Blog.findById(req.params.id);
    res.render('blog/edit',{blog})
  });
  


  module.exports = blogRouter;