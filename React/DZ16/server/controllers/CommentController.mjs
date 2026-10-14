import Comment from "../models/Comment.mjs";
import User from "../models/User.mjs";

export const getCommentsByArticle = async (req, res) => {
    try {
        const comments = await Comment.find({ articleId: req.params.id }).sort({ createdAt: 1 });
        res.send(comments);
    } catch (e) {
        res.status(400).send(e.message);
    }
};

export const createComment = async (req, res) => {
    try {
        // Підтягнути користувача, щоб зберегти зручне поле userName (email або name)
        const user = await User.findById(req._id);
        const userName = user?.name || user?.email || 'Unknown';

        const comment = new Comment({
            articleId: req.params.id,
            userId: req._id,
            userName: userName,
            content: req.body.content
        });

        await comment.save();
        res.send(comment);
    } catch (e) {
        res.status(400).send(e.message);
    }
};

export const updateComment = async (req, res) => {
    try {
        const updated = await Comment.findByIdAndUpdate(
            req.params.id,
            { content: req.body.content },
            { new: true }
        );
        res.send(updated);
    } catch (e) {
        res.status(400).send(e.message);
    }
};

export const deleteComment = async (req, res) => {
    try {
        const deleted = await Comment.findByIdAndDelete(req.params.id);
        res.send(deleted);
    } catch (e) {
        res.status(404).send(e.message);
    }
};
