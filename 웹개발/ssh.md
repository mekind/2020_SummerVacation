- SSH ��?

	client  -------> server

	������� �ϱ����� ssh�� ���

	client: ssh client ��ġ

	server: ssh server ��ġ

-���� �� ��ġ ����

	1.
	sudo apt-get purge openssh-server openssh-client

	purge�� remove(���α׷��� ����)���� ������ ����

	2. 
	sudo apt-get install openssh-server openssh-client

	3. ����
	sudo service ssh start

	4. ���� Ȯ��
	sudo ps aux | grep ssh

- �����ϱ�

	ssh {���Ӱ���}@{ip �ּ�}

	-�ڵ� �α��� 

	// ������ ���ؼ��� ���� ������ �� �ʿ���
	// ���� ����� ������ AWS�� ���� �ٸ� ����̴�.
		
		����Ű �����Ű�� ����

		ssh-keygen

		cd ~/.ssh

		id_rsa.pub --> ����Ű 

		ssh-copy-id {}@{}

	-RSA ���

