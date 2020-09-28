import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;

public class HtmlParser {
    public static void main(String[] args) {
        String text = "&amp;gt;";
        Map<String, String> map = new HashMap<String, String>() {
            {
                put("", "");
                put("&quot;", "\"");
                put("&apos;", "\'");
                put("&amp;", "%%");
                put("&gt;", ">");
                put("&lt;", "<");
                put("&frasl;", "/");
            }
        };

        Iterator<Entry<String, String>> iterator = map.entrySet().iterator();
        while (iterator.hasNext()) {
            Entry<String, String> entry = iterator.next();
            if (text.contains(entry.getKey())) {
                text = text.replace(entry.getKey(), entry.getValue());
            }
        }
        text = text.replace("%%", "&");
        System.out.println(text);
    }
}