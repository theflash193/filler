echo "entrez le message du commit :"
read message

make fclean
git add -A
git commit -m "$message"
git push