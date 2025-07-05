/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:49:20 by skohtake          #+#    #+#             */
/*   Updated: 2025/07/05 13:49:22 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h> // sigaction, SIGUSR1用
#include <stdio.h>  // printf用
#include <unistd.h> // getpid, sleep用

// 信号ハンドラ関数
// この関数は、SIGUSR1シグナルがプロセスに送信されたときに呼び出されます。
void	handle_sigusr1(int signum)
{
	printf("信号 %d (SIGUSR1) を受信しました！\n", signum);
	printf("これでシグナルハンドラが実行されました。\n");
}

int	main(void)
{
	struct sigaction sa; // sigaction構造体を宣言
	// 1. シグナルハンドラを設定
	// sigaction構造体のsa_handlerに、呼び出したい関数のアドレスを設定します。
	// この形式のハンドラは、受け取ったシグナルの番号だけを引数にとります。
	sa.sa_handler = handle_sigusr1;
	// 2. sa_flagsを設定 (ここでは特に設定なし、デフォルト動作)
	// 通常はSA_RESTARTなどを設定しますが、ここでは最も単純な形にするため0（または設定なし）にします。
	sa.sa_flags = 0;
	// 3. sa_maskを設定 (ここでは何もブロックしない)
	// sigemptysetは、シグナルハンドラ実行中にブロックするシグナルセットを空にします。
	// つまり、このハンドラが実行中に他のどんなシグナルもブロックされません。
	sigemptyset(&sa.sa_mask);
	// 4. sigaction() を呼び出してハンドラを登録
	// SIGUSR1 シグナルに対して、上で設定したsa構造体（ハンドラ情報）を登録します。
	// 3つ目の引数（NULL）は、以前のシグナル設定を取得しないことを意味します。
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigactionの登録に失敗しました");
		return (1); // エラー終了
	}
	printf("このプログラムのPIDは: %d です。\n", getpid());
	printf("別のターミナルから 'kill -SIGUSR1 %d' を実行して、SIGUSR1を送信してください。\n", getpid());
	printf("SIGUSR1を受信するまで待機中...\n");
	// プロセスを終了させずに、シグナルを待ち続けるためのループ
	// ここでプログラムが一時停止し、シグナルが来るのを待ちます。
	while (1)
	{
		sleep(1); // CPU使用率を抑えるために1秒ごとに待機
	}
	return (0);
}
