import React, { useEffect } from "react";
import { useDispatch, useSelector } from "react-redux";
import { getPosts } from "./thunks/postsThunks";

const App = () => {
  const dispatch = useDispatch();
  const posts = useSelector(state => state.posts);

  useEffect(() => {
    dispatch(getPosts());
  }, [dispatch]);

  if (posts.status === 'loading') return <div style={{ padding: 20, color: 'blue' }}>Loading...</div>;
  if (posts.status === 'failed') return <div style={{ padding: 20, color: 'red' }}>{posts.error}</div>;

  return (
    <div style={{ padding: 20 }}>
      <h2>Posts:</h2>
      {posts.data.map((post) => (
        <div key={post.id} style={{ marginBottom: 12, border: '1px solid #ccc', borderRadius: 6, padding: 10 }}>
          <h3 style={{ margin: '0 0 6px 0' }}>{post.title}</h3>
          <div>{post.body}</div>
        </div>
      ))}
    </div>
  );
};

export default App;
