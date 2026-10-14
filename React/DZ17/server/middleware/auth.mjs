import jwt from 'jsonwebtoken'
const auth = (req, res, next) => {
    try {
        const token = req.header('Authorization').replace('Bearer ', '')
        const decoded = jwt.verify(token, 'secret')
        req._id = decoded._id
        next();
    }
    catch (e) {
        res.status(401).send({ error: 'Invalid token.' })
    }
}

export default auth