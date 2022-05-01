# software2


## GitHub利用のためのPC側の設定

```
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```

## 最新の宿題ファイルをダウンロードする方法


```
git clone https://github.com/jsk-lecture/software2-<自分のgitaccount>
cd software2-<自分のgitaccount>
git remote add upstream https://github.com/jsk-lecture/software2
git fetch --all
git merge --no-edit --allow-unrelated-histories upstream/main
```

とすると、最新の宿題ファイルをダウンロードすることが出来ます．

## 追加したファイルをアップロードする方法

```
git add <追加するファイル>
git commit -m "（変更内容を記述）"
git push origin main
```

とすると変更を自分のGitHubのリポジトリにアップロードできます。
この時，手元のリポジトリとGitHubのリポジトリの整合性が取れていない場合，

```
error: failed to push some refs to 'git@github.com:jsk-lecture/software2-<自分のgitaccount>'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. Integrate the remote changes (e.g.
hint: 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```
というエラーになる．`git push -f origin main`とすると，GitHub側のリポジトリを手元のリポジトリで上書きする．通常は推奨されないが，この講義だけでは利用することになる．

パスワードはGitHubにログインする際のパスワードではなく，[Tokenを作成](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token)し，利用します．

また，
```
git config --global credential.helper store
```
とすると，TokenがPCに保存されます．
