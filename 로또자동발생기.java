import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Random;
public class LottoNum {
	public static void main(String args[]) throws Exception {  //throw절 이용 예외처리
		//로또 번호 출력할 파일명 입력 받기
		System.out.print(“번호를 출력할 파일명 입력: ”);
		String s = stdin.next();  //입력받은 파일명을 s에 대입
		FileWriter fw = new FileWriter(s, true);  //파일명으로 FileWriter 객체 생성, append: true로 파일의 끝에 문자 첨가(기존 내용 유지)
		//구매할 로또 매수 입력받기
		Scanner stdin = new Scanner(system.in);
		Int buy = 0;  //로또 매수 저장할 변수 buy 생성 후 0으로 값 초기화
		System.out.print(“구매할 로또 매수 입력: ”);  //키보드로 입력 받기
		buy = stdin.nextInt();  //키보드로 입력 받은 값 정수형으로 buy에 대입
		//로또 번호 생성하기
		Random r = new Random();  //Random 객체 생성
		for (int b = 0; b < buy; b++) {  //입력받은 매수만큼 번호생성 반복
			int[] lnum = new int[6];
			int tmp;
			int i = 0;
			a : while(i < 6) {  //레이블 블록을 이용하여 반복문 사용
				tmp = r.nextInt(45)+1;  //nextInt(45) 메소드 이용, 0~44사이 난수 발생
				for(int j = 0; j <= i; j++) {  //기존 생성값과 중복 검사, 중복되지 않게
					if (tmp == lnum[j])
						continue a;  //레이블 블록 이용하여 continue 수행
				}
			}
			lnum[i]=tmp;
			i++;
			fw.write(“로또” + (string)(i+1) + “: ” + Arrays.toString(lnum) + “\n”);  //로또 번호(정수 배열을 문자열로 변환)를 파일에 출력
		}
		fw.close();  //출력 스트림 닫기
		System.out.print(s + “ 파일이 생성되었습니다.”);
	}
}