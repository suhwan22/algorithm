# 새로 생성된 파일만 찾아오기
NEW_FILES = $(shell git status --porcelain | awk '/^\?\?/ {print $$2}')

# solved commit prefix
COMMIT_SOVLED_PREFIX = [feat] Baekjoon\#

#  새로 생성된 파일 각각에 대해 개별 add, commit
commit-each:
	@if [ -n "$(NEW_FILES)" ]; then \
		echo "\033[1m\033[33mNew files to commit: \033[0m\033[32m$(NEW_FILES)\033[0m"; \
		for file in $(NEW_FILES); do \
			dir=$$(echo $$file | cut -d'/' -f3); \
			git add $$file; \
			git commit -m "$(COMMIT_SOVLED_PREFIX)$$dir solved with c++"; \
			echo "\033[1m\033[33mcommit \033[0m \033[32m\"$(COMMIT_SOVLED_PREFIX)$$dir solved with c++\"\033[0m"; \
		done; \
	else \
		echo "\033[31mNo new files to add."; \
	fi
