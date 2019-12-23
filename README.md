# FT_LS

Hello friend,
Today's project is recoding the unix command ls, with the following flags : ```-lRatrp```.
Not that much flags, but we're really proud of what we did.

<h3>Algo used :</h3>
Basically nothing special, just a simple binary tree defined as the following :

```
typedef struct  s_tree
{
  char          *name;
  char          *fullpath;
  int           mod_time;
  struct s_tree *left;
  struct s_tree *right;
}               t_t;
```

The ```name``` variable is for the name of the file/folder.

The ```fullpath``` variable is for the full path of the file/folder.

The ```mod_time``` variable is for the modification time of the file/folder.

Have fun exploring the code :D <3
P.S : I know the code isn't really perfect and we can do better, I will get back to it and upgrade it. But for now let's focus on the new project. Making a minishell :D
