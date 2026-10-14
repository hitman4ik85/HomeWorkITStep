import express from 'express'
import dbConnection from './db/db.mjs'
import cors from 'cors'
import { createArticle, deleteArticle, getArticle, getArticles, updateArticle } from './controllers/ArticleController.mjs'
import { getAuthUser, login, register, updateProfile } from './controllers/AuthController.mjs'
import { createComment, deleteComment, getCommentsByArticle, updateComment } from './controllers/CommentController.mjs'
import { getUsers, updateUser, setUserRole, deleteUser } from './controllers/UserController.mjs'
import auth from './middleware/auth.mjs'
import isAdmin from './middleware/isAdmin.mjs'

const app = express()
const port = 5000

dbConnection.on('connected', () => console.log('Connected to MongoDB'))
dbConnection.on('error', () => console.log('Connected to MongoDB error'))

app.use(express.json())
app.use(cors());

app.get('/', (req, res) => {
  res.send('Hello!')
})

// articles
app.get('/articles', getArticles)
app.get('/articles/:id', getArticle)
app.post('/articles', auth, isAdmin, createArticle)
app.put('/articles/:id', auth, isAdmin, updateArticle)
app.delete('/articles/:id', auth, isAdmin, deleteArticle)

// auth
app.post('/register', register)
app.post('/login', login)
app.post('/authUser', auth, getAuthUser)

// profile
app.put('/profile', auth, updateProfile)

// comments
app.get('/articles/:id/comments', getCommentsByArticle)
app.post('/articles/:id/comments', auth, createComment)
app.put('/comments/:id', auth, isAdmin, updateComment)
app.delete('/comments/:id', auth, isAdmin, deleteComment)

// users (admin only)
app.get('/users', auth, isAdmin, getUsers)
app.put('/users/:id', auth, isAdmin, updateUser)
app.put('/users/:id/role', auth, isAdmin, setUserRole)
app.delete('/users/:id', auth, isAdmin, deleteUser)

app.listen(port, () => {
  console.log(`Example app listening on http://localhost:${port}`)
})
