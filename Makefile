# 새로 생성된 파일만 찾아오기
NEW_FILES = $(shell git status --porcelain | awk '/^\?\?/ {print $$2}')

# solved commit prefix
COMMIT_SOVLED_PREFIX = [feat] Baekjoon\#

# 새로 생성된 파일 각각에 대해 개별 add, commit
commit-each:
	@if [ -n "$(NEW_FILES)" ]; then \
		echo "New files to commit: $(NEW_FILES)"; \
		for file in $(NEW_FILES); do \
			dir=$$(echo $$file | cut -d'/' -f3); \
			git add $$file; \
			git commit -m "$(COMMIT_SOVLED_PREFIX)$$dir solved with c++"; \
			echo "commit => $(COMMIT_SOVLED_PREFIX)$$dir solved with c++"; \
		done; \
	else \
		echo "No new files to commit."; \
	fi
