gitpush:	
			sh .gitpush || {											\
			echo '#!/bin/sh'									> .gitpush;\
			echo 'grep -Fx .gitpush .gitignore > /dev/null \'	>> .gitpush;\
			echo '|| echo .gitpush >> .gitignore;'				>> .gitpush;\
			echo 'git status'									>> .gitpush;\
			echo 'git add .'									>> .gitpush;\
			echo 'git status'									>> .gitpush;\
			echo 'echo Enter commits name: '					>> .gitpush;\
			echo 'read commits_name'							>> .gitpush;\
			echo 'git commit -m "$$commits_name"'				>> .gitpush;\
			echo 'git push'										>> .gitpush;\
			sh .gitpush;}
			rm .gitpush
