# Security policy
Java自带的安全管理器可以限制程序的权限，从而达到安全的目的。

以下代码试图连接某机器的22端口：

```
import java.net.*;

public class EvilEmpire {
	public static void main(String[] args) throws Exception {
		try {
			Socket s = new Socket("192.168.0.32", 22);
			System.out.println("Connected!");
		} catch(SecurityException e) {
			System.out.println("SecurityException: could not connect");
		}
	}
}
```

用普通方法运行，程序可以成功连接：

```
$ java EvilEmpire
Connected!
```

若启用安全管理器，则无法连接：

```
$ java -Djava.security.manager EvilEmpire
SecurityException: could not connect
```

可以创建一个安全规则文件，显式允许程序访问远程地址：

```
grant codeBase "file:/home/jtzhao/eclipse-workspace/EvilEmpire/bin" {
  permission java.net.SocketPermission "192.168.0.32", "connect, accept, listen, resolve";
};
```

注意：codeBase中的路径，必须是class文件所在目录的路径。

运行程序时指定policy文件的位置即可：

```
$ java -Djava.security.manager -Djava.security.policy=EvilEmpire.policy EvilEmpire
Connected!
```
