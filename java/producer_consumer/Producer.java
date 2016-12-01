import java.util.concurrent.BlockingQueue;
import java.util.Date;
import java.text.SimpleDateFormat;

public class Producer implements Runnable {

    private final BlockingQueue<Work> queue;
    
    public Producer(BlockingQueue<Work> queue) {
        this.queue = queue;
    }
    
    @Override public void run() {
        while (!Thread.currentThread().interrupted()) {
            try {
                queue.put(produce());
                System.out.println("producer putting in...");
            } catch (InterruptedException ie) {
                Thread.currentThread().interrupt();
            }
        }
    }

    private Work produce() {
        String message = new SimpleDateFormat("HH:mm:ss").format(new Date());
        System.out.printf("producer putting in at %s%n", message);
        return new Work(message);
    }
}