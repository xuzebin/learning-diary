import java.util.concurrent.BlockingQueue;

public class Consumer implements Runnable {
    
    private final BlockingQueue<Work> queue;
    
    public Consumer(BlockingQueue<Work> queue) {
        this.queue = queue;
    }

    @Override public void run() {
        while (!Thread.currentThread().interrupted()) {
            try {
                consume(queue.take());
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    private void consume(Work work) {
        System.out.printf("consumer taking out at %s%n", work.getMessage());
    }

    
}