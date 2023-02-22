void connect(Node *root)

    {

       queue<Node*> q;

        q.push(root);

        while(!q.empty()) {

            int k = q.size();

            for(int i=0; i<k; i++){

            Node *t=q.front();

            q.pop();

            if(i==k-1) t->nextRight = NULL;

            else{

                t->nextRight=q.front();}

                if(t->left) q.push(t->left);

                if(t->right) q.push(t->right);

            

        }

    }}
