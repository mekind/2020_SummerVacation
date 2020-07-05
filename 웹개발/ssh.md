- SSH 란?

	client  -------> server

	원격제어를 하기위해 ssh를 사용

	client: ssh client 설치

	server: ssh server 설치

-삭제 및 설치 과정

	1.
	sudo apt-get purge openssh-server openssh-client

	purge는 remove(프로그램만 제거)보다 강력한 제거

	2. 
	sudo apt-get install openssh-server openssh-client

	3. 실행
	sudo service ssh start

	4. 실행 확인
	sudo ps aux | grep ssh

- 연결하기

	ssh {접속계정}@{ip 주소}

	-자동 로그인 

	// 사용법에 대해서는 추후 연구가 더 필요함
	// 내가 사용할 서버는 AWS라 조금 다른 방식이다.
		
		공개키 비공개키를 생성

		ssh-keygen

		cd ~/.ssh

		id_rsa.pub --> 공개키 

		ssh-copy-id {}@{}

	-RSA 방식

